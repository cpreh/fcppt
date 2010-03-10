//[noncopyable
#include <fcppt/noncopyable.hpp>

class test
{
	FCPPT_NONCOPYABLE(test)
public:
	void
	some_function()
	{
	}
};
//]

int main()
{}
