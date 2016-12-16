//==============================================================================
// rectangle.cpp
//
//  Created on: Nov 19, 2011
//      Author: pesterie
//==============================================================================

#include <square.hpp>
#include <cassert>

namespace shapes
{
  square::square() : rectangle() {}

  square::square(int w, int h)
  {
    assert(width == height);
    width = w;
    height = h;
  }

  square::square(square const& s)
  {
    width  = s.width;
    height = s.height;
  }

  square& square::operator=(square const& r)
  {
    width  = r.width;
    height = r.height;
    return *this;
  }

  void square::set_width( int w)
  {
    assert(width == height);
    width  = w;
    height = w;
  }

  void square::set_height(int h)
  {
    assert(width == height);
    height = h;
    width  = h;
  }
}
