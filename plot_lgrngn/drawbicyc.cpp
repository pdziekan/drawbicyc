#include"plot_series.hpp"
#include"plot_prof.hpp"

int main(int ac, char** av)
{
  if (ac != 2) error_macro("expecting 1 argument: dir containing out_lgrngn")

  std::string
    dir = string(av[1]),
    h5  = dir + "out_lgrngn";

  // detecting input data dimensionality
  H5::H5File h5f(h5 + "/const.h5", H5F_ACC_RDONLY);
  H5::DataSet h5d = h5f.openDataSet("G");
  H5::DataSpace h5s = h5d.getSpace();
  int NDims = h5s.getSimpleExtentNdims();

  if(NDims == 2)
  {
    plot_series(Plotter_t<2>(h5));
    plot_profiles(Plotter_t<2>(h5));
  }
  else if(NDims == 3)
  {
    plot_series(Plotter_t<3>(h5));
    plot_profiles(Plotter_t<3>(h5));
  }
  else
    assert(false && "need 2d or 3d input data");

return 0;
} // main
