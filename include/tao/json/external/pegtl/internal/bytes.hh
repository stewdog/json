// Copyright (c) 2014-2015 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef TAOCPP_JSON_EMBEDDED_PEGTL_INTERNAL_BYTES_HH
#define TAOCPP_JSON_EMBEDDED_PEGTL_INTERNAL_BYTES_HH

#include "skip_control.hh"

#include "../analysis/counted.hh"

namespace tao_json_pegtl
{
   namespace internal
   {
      template< unsigned Num >
      struct bytes
      {
         using analyze_t = analysis::counted< analysis::rule_type::ANY, Num >;

         template< typename Input >
         static bool match( Input & in )
         {
            if ( in.size() >= Num ) {
               in.bump( Num );
               return true;
            }
            return false;
         }
      };

      template< unsigned Num >
      struct skip_control< bytes< Num > > : std::true_type {};

   } // internal

} // tao_json_pegtl

#endif
