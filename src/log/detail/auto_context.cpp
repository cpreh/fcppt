//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/maybe_void.hpp>
#include <fcppt/optional_bind_construct.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/context_location.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/optional_location.hpp>
#include <fcppt/log/detail/auto_context.hpp>
#include <fcppt/log/detail/auto_context_rep.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/optional_context_location.hpp>
#include <fcppt/log/detail/optional_context_tree_ref.hpp>


fcppt::log::detail::auto_context::auto_context(
	fcppt::log::detail::optional_context_location const &_context_location,
	fcppt::log::object &_object
)
:
	rep_(
		fcppt::optional_bind_construct(
			_context_location,
			[
				&_object
			](
				fcppt::log::context_location const &_location
			)
			{
				return
					fcppt::log::detail::auto_context_rep(
						_location,
						_location.context().add(
							_location.location(),
							_object
						)
					);
			}
		)
	)
{
}

fcppt::log::detail::auto_context::~auto_context()
{
	// TODO: Make this possible using maybe_void
	/*fcppt::maybe_void(
		rep_,
		[](
			fcppt::log::detail::auto_context_rep &_rep
		)
		{
			_rep.context().remove(
				_rep.node()
			);
		}
	);*/
	if(
		rep_
	)
		rep_.get_unsafe().context().remove(
			rep_.get_unsafe().node()
		);
}

fcppt::log::optional_location
fcppt::log::detail::auto_context::location() const
{
	return
		fcppt::optional_bind_construct(
			rep_,
			[](
				fcppt::log::detail::auto_context_rep const &_rep
			)
			{
				return
					_rep.location();
			}
		);
}

fcppt::log::detail::optional_context_tree_ref const
fcppt::log::detail::auto_context::node() const
{
	return
		fcppt::optional_bind_construct(
			rep_,
			[](
				fcppt::log::detail::auto_context_rep const &_rep
			)
			-> fcppt::log::detail::context_tree &
			{
				return
					_rep.node();
			}
		);
}

void
fcppt::log::detail::auto_context::transfer(
	fcppt::log::context &_context,
	fcppt::log::object &_object
)
{
	fcppt::log::detail::auto_context_rep &rep(
		FCPPT_ASSERT_OPTIONAL_ERROR(
			rep_
		)
	);

	rep.context().remove(
		rep.node()
	);

	rep.context(
		_context
	);

	rep.node(
		_context.add(
			rep.location(),
			_object
		)
	);
}
