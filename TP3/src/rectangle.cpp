//==============================================================================
// rectangle.cpp
//
//  Created on: Nov 19, 2011
//      Author: pesterie
//==============================================================================
#include <rectangle.hpp>
#include <utility>

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

   void rectangle::set_width( int w){ width  = w; }
   void rectangle::set_height(int h){ height = h; }
   int  rectangle::get_width()  const { return width;  }
   int  rectangle::get_height() const { return height; }
   int  rectangle::area() { return width*height; }
   void rectangle::swap(rectangle& src)
   {
     std::swap(height, src.height);
     std::swap(width , src.width );
   }

   rectangle::~rectangle(){}

   std::ostream& operator<<(std::ostream& os, rectangle const& r)
   {
     for(int i = 0; i<r.get_width(); ++i) os << '-' ;
     os << '\n';
     for(int i = 0; i<r.get_height(); ++i)
     {
       os << "|";
       for(int i = 0; i<r.get_width()-2; ++i) os << ' ' ;
       os << "|\n";
     }
     for(int i = 0; i<r.get_width(); ++i) os << '-' ;
     os << '\n';
     return os;
   }

   void swap(rectangle& left, rectangle& right)
   {
     left.swap(right);
   }
}
