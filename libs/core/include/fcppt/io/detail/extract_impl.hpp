//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_DETAIL_EXTRACT_IMPL_HPP_INCLUDED
#define FCPPT_IO_DETAIL_EXTRACT_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/nothing.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{
namespace detail
{

template<
	typename Type,
	typename Ch,
	typename Traits
>
inline
fcppt::optional::object<
	Type
>
extract_impl(
	std::basic_istream<
		Ch,
		Traits
	> &_stream,
	fcppt::reference<
		Type
	> const _result
)
{
	return
		_stream
		>>
		_result.get()
		?
			fcppt::optional::make(
				std::move(
					_result.get()
				)
			)
		:
			fcppt::optional::nothing{}
		;
}

}
}
}

#endif
