//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/backtrace/current_stack_frame.hpp>
#include <fcppt/backtrace/print_current_stack_frame.hpp>
#include <fcppt/backtrace/stack_limit.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/random/variate.hpp>
#include <fcppt/random/distribution/basic.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>
#include <fcppt/random/generator/minstd_rand.hpp>
#include <fcppt/random/generator/seed_from_chrono.hpp>


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
		auto const &current_symbol
		:
		sf
	)
		fcppt::io::cout()
			<< current_symbol
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

	typedef fcppt::random::generator::minstd_rand generator_type;

	generator_type generator(
		fcppt::random::generator::seed_from_chrono<
			generator_type::seed
		>()
	);

	typedef fcppt::random::distribution::basic<
		fcppt::random::distribution::parameters::uniform_int<
			unsigned
		>
	> distribution;

	fcppt::random::variate<
		generator_type,
		distribution
	> random_depth(
		generator,
		distribution(
			distribution::param_type(
				distribution::param_type::min(
					10u),
				distribution::param_type::max(
					100u))));

	recursive_function_0(
		0u,
		random_depth());
}
