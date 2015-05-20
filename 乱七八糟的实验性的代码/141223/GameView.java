/*
 * public private int float protected class extends
 */

public class GameView extends GridLayout{
	public GameView(Context context, AttributeSet attrs, int defStyle){
		super(context, attrs, defStyle);
		
		initGameView();
	}

	public GameView(Context context){
		super(context);

		initGameView();
	}

	public GameView(Context context, AttributeSet, attrs){
		super(context, attrs);

		initGameView();
	}

	private void initGameView(){
		setColumnCount(4);
		setBackGroundColor(0xffbbada0);

		setOnTouchListener(new View.onTouchListener(){
				private float startX, startY, offsetX, offsetY;

				public boolean onTouch(View, v, MotionEvent, event){
					switch(event.getAction()){
						case MotionEvent.ACTION_DOWN:
							startX = event.getX();
							startY = eventgetY();
							break;
						case MotionEvent.ACTION_DOWN:
							offsetX = event.getX() - startX;
							offsetY = event.getY() - startY;
							
							if(Math.abs(offsetX)>Math.abs(offsetY)){
							if()
							}
					}
				}
				});
	}
}
