//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/int_range_impl.hpp>
#include <fcppt/algorithm/detail/has_reserve.hpp>
#include <fcppt/algorithm/detail/optimize_map.hpp>
#include <fcppt/config/compiler.hpp>
#include <fcppt/container/detail/has_size.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/pos_range.hpp>
#include <fcppt/container/grid/pos_ref_range.hpp>
#include <fcppt/enum/range_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <list>
#include <map>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
std::vector<
	int
>
int_vector;

template<
	typename Source
>
using
source_optimized
=
fcppt::algorithm::detail::optimize_map<
	int_vector,
	Source
>;

}

int
main()
{
	typedef
	std::map<
		int,
		int
	>
	int_int_map;

	static_assert(
		fcppt::algorithm::detail::optimize_map<
			int_vector,
			int_vector
		>::value,
		"map from vector to vector not optimized"
	);

	static_assert(
		fcppt::container::detail::has_size<
			int_vector
		>::value,
		"vector::size() not detected"
	);

	static_assert(
		fcppt::algorithm::detail::has_reserve<
			int_vector
		>::value,
		"vector::reserve() not detected"
	);

	static_assert(
		not
		fcppt::algorithm::detail::has_reserve<
			int_int_map
		>::value,
		"map does not have reserve"
	);

	static_assert(
		fcppt::container::detail::has_size<
			int_int_map
		>::value,
		"map::size() not detected"
	);

	static_assert(
		fcppt::algorithm::detail::optimize_map<
			int_vector,
			int_int_map
		>::value,
		"map from map to vector not optimized"
	);

	static_assert(
		not
		fcppt::algorithm::detail::optimize_map<
			int_int_map,
			int_vector
		>::value,
		"map from vector to map cannot be optimized"
	);

	FCPPT_PP_PUSH_WARNING
	#if defined(FCPPT_CONFIG_CLANG_COMPILER)
	FCPPT_PP_DISABLE_GCC_WARNING(-Wunneeded-member-function)
	FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-member-function)
	#endif
	FCPPT_PP_DISABLE_VC_WARNING(4822)

	struct ra_range
	{
		typedef
		int_vector::iterator
		iterator;

		iterator
		begin() const;

		iterator
		end() const;
	};

	static_assert(
		source_optimized<
			ra_range
		>::value,
		"random access iterator not detected"
	);

	struct bi_range
	{
		typedef
		std::list<
			int
		>::iterator
		iterator;

		iterator
		begin() const;

		iterator
		end() const;
	};

	static_assert(
		not
		source_optimized<
			bi_range
		>::value,
		"random access iterator not detected"
	);

	FCPPT_PP_POP_WARNING

	enum class test_enum
	{
		test1,
		fcppt_maximum = test1
	};

	static_assert(
		source_optimized<
			fcppt::enum_::range<
				test_enum
			>
		>::value,
		"enum range not optimized"
	);

	static_assert(
		source_optimized<
			fcppt::int_range<
				int
			>
		>::value,
		"int range not optimized"
	);

	static_assert(
		source_optimized<
			fcppt::container::grid::pos_range<
				unsigned,
				2
			>
		>::value,
		"grid::pos_range not optimized"
	);

	static_assert(
		source_optimized<
			fcppt::container::grid::pos_ref_range<
				fcppt::container::grid::object<
					unsigned,
					2
				>
			>
		>::value,
		"grid::pos_ref_range not optimized"
	);

	static_assert(
		source_optimized<
			brigand::list<
				int
			>
		>::value,
		"mpl vector not optimized"
	);
}
