//==============================================================================
// square.hpp
//
//  Created on: Nov 19, 2011
//      Author: pesterie
//==============================================================================

#ifndef INCLUDE_SQUARE_HPP_INCLUDED
#define INCLUDE_SQUARE_HPP_INCLUDED

#include <ostream>
#include <rectangle.hpp>

namespace shapes
{
  class square : public rectangle
  {
  public:
    square();
    square(int w, int h);
    square(square const& s);
    square& operator=(square const& r);
    void set_width( int w);
    void set_height(int h);
  };
}

#endif /*  INCLUDE_SQUARE_HPP_INCLUDED */
