//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UTF8_FACET_HPP_INCLUDED
#define FCPPT_UTF8_FACET_HPP_INCLUDED

#include <fcppt/class_symbol.hpp>

#define BOOST_UTF8_BEGIN_NAMESPACE \
namespace boost { \
namespace fcppt {

#define BOOST_UTF8_END_NAMESPACE }}

#define BOOST_UTF8_DECL FCPPT_CLASS_SYMBOL

#include <fcppt/config/external_begin.hpp>
#include <boost/detail/utf8_codecvt_facet.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace utf8
{

/// The utf-8 codecvt facet imported from boost
typedef ::boost::fcppt::utf8_codecvt_facet facet;

}
}

#endif
