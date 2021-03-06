// Copyright (c) 2014-2015 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef TAOCPP_JSON_EMBEDDED_PEGTL_INTERNAL_TRIVIAL_HH
#define TAOCPP_JSON_EMBEDDED_PEGTL_INTERNAL_TRIVIAL_HH

#include "skip_control.hh"

#include "../analysis/counted.hh"

namespace tao_json_pegtl
{
   namespace internal
   {
      template< bool Result >
      struct trivial
      {
         using analyze_t = analysis::counted< analysis::rule_type::ANY, unsigned( ! Result ) >;

         template< typename Input >
         static bool match( Input & )
         {
            return Result;
         }
      };

      template< bool Result >
      struct skip_control< trivial< Result > > : std::true_type {};

   } // internal

} // tao_json_pegtl

#endif
