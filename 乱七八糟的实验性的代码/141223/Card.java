public class Card extends PrameLayout{
	public Card(Context context){
		super(context);

		label = new TextView(getContext());
		label.setTextSize(32);
		label.setBackGroundColor(0x33ffffff);
		label.setGravity(Gravity.CENTER);
		
		LayoutParams lp = new LayoutParams(-1, -1);
		lp.setMargins(10, 10, 0, 0);
		addView(label, lp);

		setNum(0);
	}

	private int num = 0;

	public int getNum(){
		return num;
	}

	public void setNum(int num){
		this.num = num;

		if(num <= 0){
			label.setText("");
		}else{
			lable.setText(num + "");
		}
	}

	public boolean equals(Card o){
		return getNum() == o.getNum();
	}

	private TextView label;
}
