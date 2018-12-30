//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/parse/alternative_result.hpp>
#include <fcppt/variant/variadic_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		std::is_same_v<
			fcppt::parse::alternative_result<
				int,
				char
			>,
			fcppt::variant::variadic<
				int,
				char
			>
		>,
		""
	);

	static_assert(
		std::is_same_v<
			fcppt::parse::alternative_result<
				int,
				int
			>,
			int
		>,
		""
	);

	static_assert(
		std::is_same_v<
			fcppt::parse::alternative_result<
				fcppt::variant::variadic<
					int
				>,
				int
			>,
			int
		>,
		""
	);

	static_assert(
		std::is_same_v<
			fcppt::parse::alternative_result<
				fcppt::variant::variadic<
					int
				>,
				char
			>,
			fcppt::variant::variadic<
				int,
				char
			>
		>,
		""
	);

	static_assert(
		std::is_same_v<
			fcppt::parse::alternative_result<
				fcppt::variant::variadic<
					int,
					char
				>,
				fcppt::variant::variadic<
					int
				>
			>,
			fcppt::variant::variadic<
				int,
				char
			>
		>,
		""
	);

	static_assert(
		std::is_same_v<
			fcppt::parse::alternative_result<
				fcppt::variant::variadic<
					int,
					float
				>,
				char
			>,
			fcppt::variant::variadic<
				int,
				float,
				char
			>
		>,
		""
	);
}
