//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PRETTY_TYPE_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_PRETTY_TYPE_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/strong_typedef_fwd.hpp>
#include <fcppt/type_name_from_info.hpp>
#include <fcppt/options/pretty_type_impl_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief The specialization point for pretty type names.

\ingroup fcpptoptions

Specialize this struct with a static <code>fcppt::string get()</code> method in
order to override how types are printed.
*/
template<
	typename Type,
	typename Enable
>
struct pretty_type_impl
{
	static
	fcppt::string
	get()
	{
		return
			fcppt::type_name_from_info(
				typeid(
					Type
				)
			);
	}
};

template<>
struct pretty_type_impl<
	std::string
>
{
	FCPPT_OPTIONS_DETAIL_SYMBOL
	static
	fcppt::string
	get();
};

template<>
struct pretty_type_impl<
	std::wstring
>
{
	FCPPT_OPTIONS_DETAIL_SYMBOL
	static
	fcppt::string
	get();
};

template<
	typename Type,
	typename Tag
>
struct pretty_type_impl<
	fcppt::strong_typedef<
		Type,
		Tag
	>
>
{
	static
	fcppt::string
	get()
	{
		return
			fcppt::options::pretty_type_impl<
				Type
			>::get();
	}
};

}
}

#endif
