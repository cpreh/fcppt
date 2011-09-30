//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/backtrace/print_current_stack_frame.hpp>
#include <fcppt/backtrace/current_stack_frame.hpp>
#include <fcppt/backtrace/stack_limit.hpp>
#include <fcppt/random/uniform.hpp>
#include <fcppt/random/make_last_exclusive_range.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>

namespace
{
void
print_trace(
	unsigned const levels)
{
	fcppt::io::cout()
		<< FCPPT_TEXT("Descended ")
		<< levels
		<< FCPPT_TEXT(" levels, printing stack trace (manually) now...\n\n");

	fcppt::backtrace::stack_frame const sf =
		fcppt::backtrace::current_stack_frame(
			fcppt::backtrace::stack_limit(
				levels * 2u));

	fcppt::io::cout()
		<< FCPPT_TEXT("Stacktrace begin...\n");
	for(
		fcppt::backtrace::stack_frame::const_iterator current_symbol =
			sf.begin();
		current_symbol != sf.end();
		++current_symbol)
		fcppt::io::cout()
			<< (*current_symbol)
			<< FCPPT_TEXT("\n");
	fcppt::io::cout()
		<< FCPPT_TEXT("Stacktrace end.\n");

	fcppt::io::cout()
		<< FCPPT_TEXT("And the same, non-manually: \n\n");
	fcppt::backtrace::print_current_stack_frame();
}

void
recursive_function_1(
	unsigned,
	unsigned);

void
recursive_function_0(
	unsigned const current_depth,
	unsigned const maximum_depth)
{
	if(current_depth != maximum_depth)
		recursive_function_1(
			current_depth+1u,
			maximum_depth);
	else
		print_trace(
			maximum_depth);
}

void
recursive_function_1(
	unsigned const current_depth,
	unsigned const maximum_depth)
{
	if(current_depth != maximum_depth)
		recursive_function_0(
			current_depth+1u,
			maximum_depth);
	else
		print_trace(
			maximum_depth);
}
}

int
main()
{
	fcppt::io::cout()
		<< FCPPT_TEXT("Printing the current stack frame to stderr now...\n");

	fcppt::backtrace::print_current_stack_frame();

	fcppt::io::cout()
		<< FCPPT_TEXT("Ok, done, descending into a recursive function...\n");

	fcppt::random::uniform<unsigned> random_depth(
		fcppt::random::make_last_exclusive_range(
			10u,
			100u));

	recursive_function_0(
		0u,
		random_depth());
}
