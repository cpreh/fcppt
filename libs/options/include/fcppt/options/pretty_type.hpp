//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PRETTY_TYPE_HPP_INCLUDED
#define FCPPT_OPTIONS_PRETTY_TYPE_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/pretty_type_impl.hpp>


namespace fcppt
{
namespace options
{

template<
	typename Type
>
inline
fcppt::string
pretty_type()
{
	return
		fcppt::options::pretty_type_impl<
			Type
		>::get();
}

}
}

#endif
