//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INTRUSIVE_BASE_DECL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_BASE_DECL_HPP_INCLUDED

#include <fcppt/intrusive/base_fwd.hpp>
#include <fcppt/intrusive/iterator_fwd.hpp>
#include <fcppt/intrusive/list_fwd.hpp>
#include <fcppt/intrusive/detail/link_decl.hpp>


namespace fcppt
{
namespace intrusive
{

class base
{
public:
	template<
		typename Type
	>
	explicit
	base(
		fcppt::intrusive::list<
			Type
		> &
	);

	base(
		base &&
	);

	base &
	operator=(
		base &&
	);

	~base();

	void
	unlink();
private:
	fcppt::intrusive::detail::link
	move_to(
		base &
	);

	template<
		typename Type
	>
	friend class fcppt::intrusive::list;

	template<
		typename Type
	>
	friend class fcppt::intrusive::iterator;

	friend class fcppt::intrusive::detail::link;

	base();

	fcppt::intrusive::detail::link link_;
};

}
}

#endif
