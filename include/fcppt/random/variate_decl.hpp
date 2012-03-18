//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_VARIATE_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_VARIATE_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/random/variate_fwd.hpp>


namespace fcppt
{
namespace random
{

template<
	typename Generator,
	typename Distribution
>
class variate
{
	FCPPT_NONCOPYABLE(
		variate
	);
public:
	typedef Generator generator;

	typedef Distribution distribution;

	variate(
		Generator &,
		Distribution const &
	);

	~variate();

	typedef typename distribution::result_type result_type;

	result_type
	operator()();
private:
	generator &generator_;

	distribution distribution_;
};

}
}

#endif
