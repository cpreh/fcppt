//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[alignment
#include <fcppt/alignment/make_type.hpp>
#include <fcppt/alignment/size_type.hpp>
#include <fcppt/alignment/is_aligned.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

int main()
{
	// create an integral constant that tells which alignment we want
	fcppt::alignment::size_type const alignment(
		16
	);

	// typedef an int with the given alignment of 16
	typedef fcppt::alignment::make_type<
		int,
		alignment
	>::type int_aligned_16;

	// create an int that is aligned to 16 bytes
	int_aligned_16 const test(
		42
	);

	fcppt::io::cout
		<< std::boolalpha
		<< fcppt::alignment::is_aligned(
			&test,
			alignment
		)
		<< FCPPT_TEXT('\n');
}
//]
