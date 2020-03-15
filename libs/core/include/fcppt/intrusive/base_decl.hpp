//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INTRUSIVE_BASE_DECL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_BASE_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/intrusive/base_fwd.hpp>
#include <fcppt/intrusive/iterator_fwd.hpp>
#include <fcppt/intrusive/list_fwd.hpp>


namespace fcppt
{
namespace intrusive
{

/**
\brief The base class of an element.

\ingroup fcpptintrusive

Every type that is used as an element of an #fcppt::intrusive::list must derive from this class.

\tparam Type The derived type.
*/
template<
	typename Type
>
class base
{
	FCPPT_NONCOPYABLE(
		base
	);
public:
	using
	list_type
	=
	fcppt::intrusive::list<
		Type
	>;

	/**
	\brief Inserts the element at the back of a list.
	*/
	explicit
	base(
		list_type &
	);

	base(
		base &&
	)
	noexcept;

	base &
	operator=(
		base &&
	)
	noexcept;

	~base();

	/**
	\brief Unlinks this element from the list.
	*/
	void
	unlink()
	noexcept;
private:
	template<
		typename T
	>
	friend class fcppt::intrusive::list;

	template<
		typename T
	>
	friend class fcppt::intrusive::iterator;

	base();

	base *prev_;

	base* next_;
};

}
}

#endif
