//==============================================================================
// main.cpp
// Author: pesterie
//==============================================================================
#include <iostream>
#include <rectangle.hpp>
#include <square.hpp>
#include <cstdlib>
#include <boost/swap.hpp>

class area_exc: public std::exception
{
  virtual const char* what() const throw()
  {
    return "Area is invalid !";
  }
} test_area_exc;

int test_area(shapes::rectangle & r)
{
  int w = rand() % 100 + 1;
  int h = rand() % 100 + 1;
  r.set_width(w);
  r.set_height(h);
  int a = r.area();
  if(w*h != a) throw test_area_exc;
  return a;
}

int main()
{
  //Test de la classe rectangle
  shapes::rectangle r(3,5);
  shapes::rectangle r_(r);
  r.set_width(4);
  r.set_height(6);
  shapes::rectangle c = r;
  // ADL here !
  boost::swap(r,r_);
  std::cout << r;
  std::cout << r_;

  //Test de la classe square
  shapes::square s(3,3);
  shapes::square s_(s);
  s.set_width(4);
  s.set_height(6);
  shapes::square c_ = s;
  // ADL here !
  boost::swap(s,s_);
  std::cout << s;
  std::cout << s_;

  //LSP non respecté !
  try{
    int res  = test_area(r);
    int res_ = test_area(s);
  }
  catch(std::exception& e){ std::cout << e.what() << std::endl; }

  return 0;
}
