//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/enum_is_empty.hpp>
#include <fcppt/enum_size.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/container/bitfield/array.hpp>
#include <fcppt/container/bitfield/default_internal_type.hpp>
#include <fcppt/container/bitfield/object.hpp>
#include <fcppt/container/bitfield/object_from_enum.hpp>
#include <fcppt/container/bitfield/proxy.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class empty_enum
{
};

}

namespace fcppt
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<>
struct enum_is_empty<
	empty_enum
>
:
std::true_type
{
};

FCPPT_PP_POP_WARNING

}

template
class
fcppt::container::bitfield::object<
	empty_enum,
	fcppt::enum_size<
		empty_enum
	>::type
>;

template
class
fcppt::container::bitfield::proxy<
	fcppt::container::bitfield::array<
		fcppt::enum_size<
			empty_enum
		>::type,
		fcppt::container::bitfield::default_internal_type
	>
>;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_bitfield_empty
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::bitfield::object_from_enum<
		empty_enum
	>
	empty_bitfield;

	empty_bitfield field{
		fcppt::no_init()
	};

	BOOST_CHECK_EQUAL(
		empty_bitfield::static_size::value,
		0u
	);
}
