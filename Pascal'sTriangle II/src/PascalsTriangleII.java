import java.util.ArrayList;
import java.util.List;

public class PascalsTriangleII {

	public List<Integer> getRow(int rowIndex) {
		List<Integer> list=new ArrayList<Integer>();
		if(rowIndex==0){
			list.add(1);
			return list;
		}
		for(int i=0;i<=rowIndex;i++){
			if(i==0){
				list.add(1);
			}
			else{
				Long t=(long) 1;
				for(int j=1;j<=i;j++){
					t=t*(rowIndex+1-j)/j;
				}
				
				long p=t;
				Integer q=(int) p;
				list.add(q);
			}
		}
		return list;
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	}

}
