//==============================================================================
// rectangle.hpp
//
//  Created on: Nov 19, 2011
//      Author: pesterie
//==============================================================================

#ifndef INCLUDE_RECTANGLE_HPP_INCLUDED
#define INCLUDE_RECTANGLE_HPP_INCLUDED

#include <ostream>

namespace shapes
{
  class rectangle
  {
  public:
    rectangle();
    rectangle(rectangle const& rs);
    rectangle(int w, int h);
    virtual ~rectangle();
    rectangle& operator=(rectangle const& r);
    virtual void set_width( int w);
    virtual void set_height(int h);
    virtual int  get_width()  const;
    virtual int  get_height() const;
    virtual int  area();
    virtual void swap(rectangle& src);

  protected:
    int width;
    int height;
  };

  std::ostream& operator<<(std::ostream& os, rectangle const& r);
  //ADL swap
  void swap(rectangle& left, rectangle& right);
}

#endif /*  INCLUDE_RECTANGLE_HPP_INCLUDED */
