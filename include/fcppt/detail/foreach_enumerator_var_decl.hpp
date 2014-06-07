//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_FOREACH_ENUMERATOR_VAR_DECL_HPP_INCLUDED
#define FCPPT_DETAIL_FOREACH_ENUMERATOR_VAR_DECL_HPP_INCLUDED

#include <fcppt/enum_size_type.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/detail/foreach_enumerator_var_fwd.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Enum
>
class foreach_enumerator_var
{
	FCPPT_NONCOPYABLE(
		foreach_enumerator_var
	);
public:
	typedef typename fcppt::enum_size_type<
		Enum
	>::type size_type;

	explicit
	foreach_enumerator_var(
		Enum start
	);

	foreach_enumerator_var(
		Enum start,
		Enum max
	);

	~foreach_enumerator_var();

	bool
	running() const;

	void
	increment();

	operator
	Enum() const;

	explicit
	operator
	size_type() const;
private:
	foreach_enumerator_var(
		Enum start,
		size_type end
	);

	size_type index_;

	size_type const end_;
};

}
}

#endif
