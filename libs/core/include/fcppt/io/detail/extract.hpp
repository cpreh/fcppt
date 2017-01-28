//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_DETAIL_EXTRACT_HPP_INCLUDED
#define FCPPT_IO_DETAIL_EXTRACT_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/io/detail/extract_impl.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/constructible_from.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <iosfwd>
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
typename
boost::enable_if<
	fcppt::type_traits::constructible_from<
		Type,
		fcppt::no_init
	>,
	fcppt::optional::object<
		Type
	>
>::type
extract(
	std::basic_istream<
		Ch,
		Traits
	> &_stream
)
{
	// TODO: Why does this warning appear here?
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wmaybe-uninitialized)

	Type result{
		fcppt::no_init{}
	};

FCPPT_PP_POP_WARNING

	return
		fcppt::io::detail::extract_impl(
			_stream,
			fcppt::make_ref(
				result
			)
		);
}

template<
	typename Type,
	typename Ch,
	typename Traits
>
inline
typename
boost::disable_if<
	fcppt::type_traits::constructible_from<
		Type,
		fcppt::no_init
	>,
	fcppt::optional::object<
		Type
	>
>::type
extract(
	std::basic_istream<
		Ch,
		Traits
	> &_stream
)
{
	Type result;

	return
		fcppt::io::detail::extract_impl(
			_stream,
			fcppt::make_ref(
				result
			)
		);
}

}
}
}

#endif
