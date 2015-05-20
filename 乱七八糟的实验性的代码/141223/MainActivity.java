public class MainActivity extends Activity{
	public MainActivity(){
		mainActivity = this;
	}

	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		tvScore = (TextView)findViewById(R.id.tvScore);
	}

	public boolean onCreateOptionsMenu(Menu menu){
		getMenuInFlater().inflate(R.menu.main, menu);
		return true;
	}

	public void clearScore(){
		score = 0;
		showScore();
	}

	public void showScore(){
		tvScore.setText(score + "");
	}

	public void addScore(int s){
		score += s;
		showScore();
	}

	private int score = 0;
	private TextView tvScore;

	private static MainActivity mainActivity = null;

	public static MainActivity getMainAcivity(){
		return mainActivity;
	}
}
