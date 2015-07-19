//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/weak_ptr_impl.hpp>
#include <fcppt/io/cout.hpp>


int
main()
{
//! [weak_ptr]
	typedef
	fcppt::weak_ptr<
		int
	>
	weak_int_ptr;

	typedef
	fcppt::shared_ptr<
		int
	>
	shared_int_ptr;

	typedef
	fcppt::optional<
		shared_int_ptr
	>
	optional_shared_int_ptr;

	optional_shared_int_ptr int_ptr(
		fcppt::make_shared_ptr<
			int
		>(
			42
		)
	);

	// Create a weak_ptr to the shared_ptr
	weak_int_ptr weak_p(
		int_ptr.get_unsafe()
	);

	if(
		weak_p.lock().has_value()
	)
		fcppt::io::cout()
			<< FCPPT_TEXT("A shared ptr is still alive.\n");

	// Delete the shared_ptr
	int_ptr =
		optional_shared_int_ptr();

	// Observe if a shared_ptr is still alive. At this point, no
	// shared_ptr is alive.
	if(
		!weak_p.lock().has_value()
	)
		fcppt::io::cout()
			<< FCPPT_TEXT("No shared ptrs are alive.\n");
//! [weak_ptr]
}
