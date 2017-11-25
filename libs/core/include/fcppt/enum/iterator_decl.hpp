//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_ENUM_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/enum/iterator_fwd.hpp>
#include <fcppt/enum/size_type.hpp>
#include <fcppt/enum/detail/iterator_base.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace enum_
{

/**
\ingroup fcpptenum
*/
template<
	typename Enum
>
class iterator final
:
	public
		fcppt::enum_::detail::iterator_base<
			Enum
		>
{
public:
	typedef
	fcppt::enum_::size_type<
		Enum
	>
	size_type;

	iterator()
	noexcept;

	explicit
	iterator(
		size_type
	)
	noexcept;
private:
	friend class boost::iterator_core_access;

	void
	increment()
	noexcept;

	bool
	equal(
		iterator
	) const
	noexcept;

	Enum
	dereference() const
	noexcept;

	size_type value_;
};

}
}

#endif
