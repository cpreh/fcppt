//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MANY_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_MANY_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/many_fwd.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/record/element_to_type_tpl.hpp>
#include <fcppt/record/map_elements.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief A parser for zero or more elements.

\ingroup fcpptoptions

Wraps a parser such that it may apply zero or more times. The result type is a
record that adds one layer of <code>std::vector</code> to the elements of the
result type of \a Parser.

\see fcppt::options::make_many
*/
template<
	typename Parser
>
class many
{
public:
	explicit
	many(
		Parser const &
	);

	explicit
	many(
		Parser &&
	);

	typedef
	fcppt::record::map_elements<
		typename
		Parser::result_type,
		std::vector<
			fcppt::record::element_to_type_tpl<
				boost::mpl::_
			>
		>
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
