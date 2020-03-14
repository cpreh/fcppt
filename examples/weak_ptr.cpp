//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/weak_ptr_impl.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>


int
main()
try
{
//! [weak_ptr]
	using
	weak_int_ptr
	=
	fcppt::weak_ptr<
		int
	>;

	using
	shared_int_ptr
	=
	fcppt::shared_ptr<
		int
	>;

	weak_int_ptr weak_p;

	{
		shared_int_ptr const int_ptr(
			fcppt::make_shared_ptr<
				int
			>(
				1
			)
		);

		// Create a weak_ptr to the shared_ptr
		weak_p =
			weak_int_ptr{
				int_ptr
			};

		if(
			weak_p.lock().has_value()
		)
		{
			fcppt::io::cout()
				<< FCPPT_TEXT("A shared ptr is still alive.\n");
		}
	}

	// Observe if a shared_ptr is still alive. At this point, no
	// shared_ptr is alive.
	if(
		!weak_p.lock().has_value()
	)
	{
		fcppt::io::cout()
			<< FCPPT_TEXT("No shared ptrs are alive.\n");
	}
//! [weak_ptr]
}
catch(
	std::exception const &
)
{
}
