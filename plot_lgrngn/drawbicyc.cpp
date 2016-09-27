#include"plot_series.hpp"
#include"plot_prof.hpp"
// command-line option handling
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
namespace po = boost::program_options;

// some globals for option handling
int ac;
char** av; 
po::options_description opts_main("General options");


int main(int argc, char** argv)
{
  // make args global
  ac=argc;
  av=argv;

  // general opts
  opts_main.add_options()
    ("prof", po::value<bool>()->default_value(true), "plot profiles?")
    ("series", po::value<bool>()->default_value(true) , "plot series?")
    ("dir", po::value<std::string>()->required() , "directory containing out_lgrngn")
  ;

  po::variables_map vm;
  po::store(po::command_line_parser(ac, av).options(opts_main).allow_unregistered().run(), vm); //     ignores unknown

  // checking if all required options present
  po::notify(vm);

  // parse dir name
  std::string
    dir = vm["dir"].as<std::string>(),
    h5  = dir + "out_lgrngn";

  // reading required plot types
  bool flag_series = vm["series"].as<bool>(),
       flag_profiles = vm["prof"].as<bool>();

  // detecting input data dimensionality
  H5::H5File h5f(h5 + "/const.h5", H5F_ACC_RDONLY);
  H5::DataSet h5d = h5f.openDataSet("G");
  H5::DataSpace h5s = h5d.getSpace();
  int NDims = h5s.getSimpleExtentNdims();

  if(NDims == 2)
  {
    if(flag_series)   plot_series(Plotter_t<2>(h5));
    if(flag_profiles) plot_profiles(Plotter_t<2>(h5));
  }
  else if(NDims == 3)
  {
    if(flag_series)   plot_series(Plotter_t<3>(h5));
    if(flag_profiles) plot_profiles(Plotter_t<3>(h5));
  }
  else
    assert(false && "need 2d or 3d input data");

return 0;
} // main
