//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_SUB_COMMAND_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_SUB_COMMAND_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/sub_command_fwd.hpp>


namespace fcppt
{
namespace options
{

template<
	typename Parser
>
class sub_command
{
public:
	sub_command(
		fcppt::string &&,
		Parser &&
	);

	fcppt::string const &
	name() const;

	Parser const &
	parser() const;

	typedef
	fcppt::options::result_of<
		Parser
	>
	result_type;
private:
	fcppt::string name_;

	Parser parser_;
};

}
}

#endif
