// Copyright (c) 2014-2015 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef TAOCPP_JSON_EMBEDDED_PEGTL_INTERNAL_ENABLE_HH
#define TAOCPP_JSON_EMBEDDED_PEGTL_INTERNAL_ENABLE_HH

#include "skip_control.hh"
#include "seq.hh"
#include "rule_match_three.hh"

#include "../analysis/generic.hh"

namespace tao_json_pegtl
{
   namespace internal
   {
      template< typename ... Rules >
      struct enable
      {
         using analyze_t = analysis::generic< analysis::rule_type::SEQ, Rules ... >;

         template< apply_mode, template< typename ... > class Action, template< typename ... > class Control, typename Input, typename ... States >
         static bool match( Input & in, States && ... st )
         {
            return rule_match_three< seq< Rules ... >, apply_mode::ACTION, Action, Control >::match( in, st ... );
         }
      };

      template< typename ... Rules >
      struct skip_control< enable< Rules ... > > : std::true_type {};

   } // internal

} // tao_json_pegtl

#endif
