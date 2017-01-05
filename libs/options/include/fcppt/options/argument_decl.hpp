//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_ARGUMENT_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_ARGUMENT_DECL_HPP_INCLUDED

#include <fcppt/options/argument_fwd.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/record/element_fwd.hpp>
#include <fcppt/record/variadic_fwd.hpp>


namespace fcppt
{
namespace options
{

template<
	typename Label,
	typename Type
>
struct argument
{
	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			Label,
			Type
		>
	>
	record_type;

	static
	fcppt::options::result<
		record_type
	>
	parse(
		fcppt::options::state &
	);
};

}
}

#endif
