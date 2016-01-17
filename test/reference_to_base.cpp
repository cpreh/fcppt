//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	reference_to_base
)
{

FCPPT_PP_POP_WARNING

	class base
	{
		FCPPT_NONCOPYABLE(
			base
		);
	public:
		base()
		{
		}

		virtual
		~base()
		{
		}
	};

	class derived
	:
		public base
	{
		FCPPT_NONCOPYABLE(
			derived
		);
	public:
		derived()
		:
			base()
		{
		}

		~derived()
		{
		}
	};

	{
		derived nonconst_derived;

		fcppt::reference<
			base
		> const nonconst_base(
			fcppt::reference_to_base<
				base
			>(
				fcppt::make_ref(
					nonconst_derived
				)
			)
		);

		BOOST_CHECK_EQUAL(
			&nonconst_derived,
			nonconst_base.get_pointer()
		);
	}

	{
		derived const const_derived{};

		fcppt::reference<
			base const
		> const const_base(
			fcppt::reference_to_base<
				base const
			>(
				fcppt::make_cref(
					const_derived
				)
			)
		);

		BOOST_CHECK_EQUAL(
			&const_derived,
			const_base.get_pointer()
		);
	}
}
