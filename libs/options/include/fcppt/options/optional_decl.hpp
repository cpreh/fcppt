//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_OPTIONAL_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTIONAL_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/optional_fwd.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/record/element_fwd.hpp>
#include <fcppt/record/variadic_fwd.hpp>


namespace fcppt
{
namespace options
{

/**
\brief An optional parser.

\ingroup fcpptoptions

Wraps a parser such that it may fail. The result is stored in a record that has
a single element with label \a Label that stores
<code>Parser::result_type</code> as an optional.

\see fcppt::options::make_optional

\tparam Label An \link fcppt::record::label\endlink.
*/
template<
	typename Label,
	typename Parser
>
class optional
{
public:
	explicit
	optional(
		Parser const &
	);

	explicit
	optional(
		Parser &&
	);

	typedef
	fcppt::optional::object<
		typename
		Parser::result_type
	>
	optional_result_type;

	typedef
	fcppt::record::element<
		Label,
		optional_result_type
	>
	element_type;

	typedef
	fcppt::record::variadic<
		element_type
	>
	result_type;

	fcppt::options::result<
		result_type
	>
	parse(
		fcppt::options::state &
	) const;

	fcppt::options::has_parameter_set
	parameters() const;

	fcppt::string
	usage() const;
private:
	Parser parser_;
};

}
}

#endif
