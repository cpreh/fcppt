//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/map.hpp>
#include <fcppt/record/permute.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"record::map",
	"[record]"
)
{
	FCPPT_RECORD_MAKE_LABEL(
		int_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		move_only_label
	);

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			int_label,
			fcppt::optional::object<
				int
			>
		>,
		fcppt::record::element<
			move_only_label,
			fcppt::optional::object<
				fcppt::unique_ptr<
					int
				>
			>
		>
	>
	result_type;

	result_type const result{
		fcppt::record::permute<
			result_type
		>(
			fcppt::record::map(
				fcppt::record::variadic<
					fcppt::record::element<
						int_label,
						int
					>,
					fcppt::record::element<
						move_only_label,
						fcppt::unique_ptr<
							int
						>
					>
				>{
					int_label{} =
						42,
					move_only_label{} =
						fcppt::make_unique_ptr<
							int
						>(
							100
						)
				},
				[](
					auto &&_value
				)
				{
					return
						fcppt::optional::make(
							std::forward<
								decltype(
									_value
								)
							>(
								_value
							)
						);
				}
			)
		)
	};

	CHECK(
		fcppt::record::get<
			int_label
		>(
			result
		)
		==
		fcppt::optional::make(
			42
		)
	);

	CHECK(
		fcppt::record::get<
			move_only_label
		>(
			result
		).has_value()
	);
}
