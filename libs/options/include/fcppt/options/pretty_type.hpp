//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PRETTY_TYPE_HPP_INCLUDED
#define FCPPT_OPTIONS_PRETTY_TYPE_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/custom_pretty_type.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Returns a pretty type used for help texts.

\ingroup fcpptoptions

Using \link fcppt::options::custom_pretty_type\endlink, one can specialize how a
type name is represented as a string. For example, the pretty name of
<code>std::string</code> is simply <code>string</code> instead of
<code>std::basic_string<char,std::char_traits<char>,std::allocator<char>></code>.
*/
template<
	typename Type
>
inline
fcppt::string
pretty_type()
{
	return
		fcppt::options::custom_pretty_type<
			Type
		>::get();
}

}
}

#endif
