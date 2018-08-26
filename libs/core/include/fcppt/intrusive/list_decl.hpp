//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INTRUSIVE_LIST_DECL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_LIST_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/intrusive/base_decl.hpp>
#include <fcppt/intrusive/iterator_fwd.hpp>
#include <fcppt/intrusive/list_fwd.hpp>


namespace fcppt
{
namespace intrusive
{

/**
\brief An intrusive list.

\ingroup fcpptintrusive

Elements that are going to be part of a list must derive from
<code>fcppt::intrusive::base<Type></code>. They get a list as a constructor
parameter and as long as they are not destroyed or moved from, they are part of
the list.
*/
template<
	typename Type
>
class list
{
	FCPPT_NONCOPYABLE(
		list
	);
public:
	list();

	list(
		list &&
	);

	list &
	operator=(
		list &&
	);

	~list();

	typedef
	fcppt::intrusive::iterator<
		Type
	>
	iterator;

	typedef
	fcppt::intrusive::iterator<
		Type const
	>
	const_iterator;

	iterator
	begin();

	iterator
	end();

	const_iterator
	begin() const;

	const_iterator
	end() const;

	bool
	empty() const;
private:
	typedef
	fcppt::intrusive::base<
		Type
	>
	base_type;

	template<
		typename T
	>
	friend class fcppt::intrusive::base;

	base_type head_;
};

}
}

#endif
