//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_DETAIL_DYNAMIC_EXN_HPP_INCLUDED
#define FCPPT_CAST_DETAIL_DYNAMIC_EXN_HPP_INCLUDED

#include <fcppt/cast/bad_dynamic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <stdexcept>
#include <typeindex>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{
namespace detail
{

template<
	typename Dest,
	typename Src
>
Dest
dynamic_exn(
	Src &_src
)
{
	try
	{
		return
			dynamic_cast<
				Dest
			>(
				_src
			);
	}
	catch(
		std::bad_cast const &
	)
	{
		throw
			fcppt::cast::bad_dynamic{
				std::type_index(
					typeid(
						_src
					)
				),
				std::type_index(
					typeid(
						Dest
					)
				)
			};
	}
}

}
}
}

#endif
