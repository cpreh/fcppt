//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_GENERATOR_BASIC_PSEUDO_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_GENERATOR_BASIC_PSEUDO_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/random/generator/basic_pseudo_fwd.hpp>

namespace fcppt
{
namespace random
{
namespace generator
{

template<
	typename Wrapped
>
class basic_pseudo
{
	FCPPT_NONCOPYABLE(
		basic_pseudo
	);
public:\

	typedef Wrapped wrapped;

	typedef typename wrapped::result_type result_type;

	FCPPT_MAKE_STRONG_TYPEDEF(
		result_type,
		seed
	);

	explicit
	basic_pseudo(
		seed
	);

	~basic_pseudo();

	result_type
	operator()();

	result_type
	min() const;

	result_type
	max() const;
private:
	wrapped wrapped_;
};

}
}
}

#endif
