//==============================================================================
// rectangle.cpp
//
//  Created on: Nov 19, 2011
//      Author: pesterie
//==============================================================================
#include <rectangle.hpp>

namespace shapes
{
   rectangle::rectangle() : width(0), height(0) {}

   rectangle::rectangle(rectangle const& rs)
   {
     width  = rs.width;
     height = rs.height;
   }

   rectangle::rectangle(int w, int h) : width(w), height(h)
   {}

   rectangle& rectangle::operator=(rectangle const& r)
   {
     width  = r.width;
     height = r.height;
     return *this;
   }

   void rectangle::set_width( int w){ width = w; }
   void rectangle::set_height(int h){ height = h; }
   int  rectangle::area() { return width*height; }
}
