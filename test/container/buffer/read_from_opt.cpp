//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/literal.hpp>
#include <fcppt/container/buffer/object.hpp>
#include <fcppt/container/buffer/read_from_opt.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_buffer_read_from_opt
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::buffer::object<
		int
	>
	buffer_type;

	typedef
	fcppt::optional::object<
		buffer_type
	>
	optional_buffer_type;

	optional_buffer_type const result1{
		fcppt::container::buffer::read_from_opt<
			buffer_type
		>(
			10u,
			[](
				buffer_type::pointer,
				buffer_type::size_type
			)
			{
				return
					fcppt::optional::object<
						buffer_type::size_type
					>();
			}
		)
	};

	BOOST_CHECK(
		!result1.has_value()
	);

	optional_buffer_type const result2{
		fcppt::container::buffer::read_from_opt<
			buffer_type
		>(
			10u,
			[](
				buffer_type::pointer,
				buffer_type::size_type
			)
			{
				return
					fcppt::optional::make(
						fcppt::literal<
							buffer_type::size_type
						>(
							0u
						)
					);
			}
		)
	};

	BOOST_CHECK(
		result2.has_value()
	);

}
