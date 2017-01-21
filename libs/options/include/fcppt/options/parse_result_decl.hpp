//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PARSE_RESULT_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_PARSE_RESULT_DECL_HPP_INCLUDED

#include <fcppt/options/parse_result_fwd.hpp>
#include <fcppt/options/state.hpp>


namespace fcppt
{
namespace options
{

/**
\brief The result of a parse, including the remaining state.

\ingroup fcpptoptions
*/
template<
	typename Result
>
class parse_result
{
public:
	parse_result(
		Result &&,
		fcppt::options::state &&
	);

	Result const &
	value() const;

	/**
	\brief The remaining state after the parse.

	Each argument, flag and option that has not been consumed by the parse
	remains in this object.
	*/
	fcppt::options::state &
	remaining_state();
private:
	Result value_;

	fcppt::options::state state_;
};

}
}

#endif
