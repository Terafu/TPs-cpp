//==============================================================================
// rectangle.hpp
//
//  Created on: Nov 19, 2011
//      Author: pesterie
//==============================================================================

#ifndef INCLUDE_RECTANGLE_HPP_INCLUDED
#define INCLUDE_RECTANGLE_HPP_INCLUDED

namespace shapes
{
  class rectangle
  {
  public:
    virtual ~rectangle();
    rectangle();
    rectangle(rectangle const& rs);
    rectangle(int w, int h);
    rectangle& operator=(rectangle const& r);

    virtual void set_width( int w);
    virtual void set_height(int h);
    virtual int  area();

  private:
    int width;
    int height;
  };
}

#endif /*  INCLUDE_RECTANGLE_HPP_INCLUDED */
