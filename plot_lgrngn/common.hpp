#pragma once

#include <iostream>
#include <iomanip>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include "gnuplot.hpp"

using std::set;
using std::string;
using std::ostringstream;
using std::cerr;
using std::endl;
using std::exception;
using std::vector;

#include <boost/units/systems/si.hpp>
namespace si = boost::units::si;
using boost::units::quantity;


// error reporting
#define error_macro(msg) \
{ \
  cerr << "error: " << msg << endl; \
  throw exception(); \
}

#define notice_macro(msg) \
{ \
  cerr << " info: " << msg << endl; \
}

string zeropad(int n, int w=3)
{
  std::ostringstream tmp;
  tmp << std::setw(w) << std::setfill('0') << n;
  return tmp.str();
}

using namespace blitz;

double iscloudy(double x)
{
  return x > 20. ? 1. : 0.; 
}
BZ_DECLARE_FUNCTION(iscloudy)

double isdowndraught(double x)
{
  return  x < -0.2 ? 1. : 0.; 
}
BZ_DECLARE_FUNCTION(isdowndraught)

double isupdraught(double x)
{
  return  x > 0.2 ? 1. : 0.; 
}
BZ_DECLARE_FUNCTION(isupdraught)

