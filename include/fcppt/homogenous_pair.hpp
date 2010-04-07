#ifndef FCPPT_HOMOGENOUS_PAIR_HPP_HPP_INCLUDED
#define FCPPT_HOMOGENOUS_PAIR_HPP_HPP_INCLUDED

namespace fcppt
{
/// std::pair<T,U> with T = U, as to allow typedef T value_type;
template
<
	typename T
>
class homogenous_pair
{
public:
	typedef 
	T 
	value_type;

	value_type first;
	value_type second;

	explicit
	homogenous_pair() 
	: 
		first(),
		second() 
	{}

	explicit
	homogenous_pair(
		value_type const &_first,
		value_type const &_second)
	:
		first(
			_first),
		second(
			_second)
	{
	}

	bool 
	operator<(
		homogenous_pair const &_p) const
	{
		if (first < _p.first)
			return true;
		if (_p.first < first)
			return false;
		return second < _p.second;
	}
};
}

#endif
