//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/variant/recursive.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace
{

//! [variant_recursive_declaration]
// Forward declare a wrapper struct that holds the to be declared variant
struct wrapper;

// Typedef a variant that can either hold an int or a struct wrapper.
// Note, that wrapper has be made recursive.
typedef fcppt::variant::object<
	boost::mpl::vector2<
		fcppt::variant::recursive<
			wrapper
		>,
		int
	>
> recursive_variant;

// Wrapper holds the variant again!
struct wrapper
{
	wrapper(
		recursive_variant const &_member
	)
	:
		member_(_member)
	{}

	recursive_variant member_;
};
//! [variant_recursive_declaration]

// declare an output operator for wrapper (just for our test case)
template<
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
operator <<(
	std::basic_ostream<
		Ch,
		Traits
	> &stream_,
	wrapper const &_wrapper
)
{
	return
		stream_ << _wrapper.member_;
}

}

int main()
try
{
//! [variant_recursive_construction]
	// The variant can hold an int
	recursive_variant rv(
		42
	);

	// Or it can hold a wrapper struct, holding a variant of the same type in return
	recursive_variant rrv((
		::wrapper(
			rv
		)
	));

	// We can extract wrapper from the variant as if the recursive wasn't there
	std::cout
		<<
		rrv.get<
			::wrapper
		>()
		.member_.get<
			int
		>()
		<< '\n';
//! [variant_recursive_construction]

	// rrv will be correctly dispatched to our wrapper struct, which will output the int
	std::cout
		<< rrv
		<< '\n';

}
catch(
	fcppt::exception const &_error
)
{
	fcppt::io::cerr()
		<< _error.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
