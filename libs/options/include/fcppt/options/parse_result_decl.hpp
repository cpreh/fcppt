//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PARSE_RESULT_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_PARSE_RESULT_DECL_HPP_INCLUDED

#include <fcppt/options/state.hpp>
#include <fcppt/options/parse_result_fwd.hpp>


namespace fcppt
{
namespace options
{

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

	fcppt::options::state &
	remaining_state();
private:
	Result value_;

	fcppt::options::state state_;
};

}
}

#endif
