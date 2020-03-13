//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_CONST_HPP_INCLUDED
#define FCPPT_DETAIL_CONST_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Type
>
class const_
{
public:
	explicit
	const_(
		Type _value
	)
	:
		value_{
			std::move(
				_value
			)
		}
	{
	}

	Type
	operator()() const
	{
		return
			value_;
	}
private:
	Type value_;
};

}
}

#endif
