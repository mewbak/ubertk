#include "ubertk.h"
#include "utk_gfx.h"

#if defined(unix) || defined(__unix__)
#include <time.h>
#include <sys/time.h>
#else 
#include <windows.h>
#endif	/* unix */

#include "cursor.inl"

namespace utk {

static Container *root_widget;

Container *init(int x, int y)
{
	NullBox *cont = new NullBox;
	cont->set_size(x, y);
	cont->set_pos(0, 0);
	root_widget = cont;
	return cont;
}

void close(Container *root)
{
	if(!root) root = root_widget;
	delete root;
}

void draw(Container *root)
{
	if(!root) root = root_widget;

	IVec2 cpos, csz;
	cpos = root->get_pos();
	csz = root->get_size();

	gfx::push_clip();
	gfx::set_clip(cpos.x, cpos.y, cpos.x + csz.x, cpos.y + csz.y);
	root->draw();
	

	// draw cursor
	gfx::image(get_mouse_pos().x, get_mouse_pos().y, utk_cursor_image, 24, 24);

	gfx::pop_clip();
}

Container *get_root_widget()
{
	return root_widget;
}

unsigned int get_msec()
{
#if defined(__unix__) || defined(unix)
	static struct timeval timeval, first_timeval;
	
	gettimeofday(&timeval, 0);

	if(first_timeval.tv_sec == 0) {
		first_timeval = timeval;
		return 0;
	}
	return (timeval.tv_sec - first_timeval.tv_sec) * 1000 + (timeval.tv_usec - first_timeval.tv_usec) / 1000;
#else
	return GetTickCount();
#endif	/* __unix__ */
}

}	// namespace utk end
