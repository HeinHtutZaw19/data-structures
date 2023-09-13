public class Copy{
  public static void main(String[] args){
    int[][] data = {{1,2,3}, {4,5,6}};
    int[][] data2 = data.clone();
    data2[1][2] = 10;
    for(int i=0;i<data.length;i++){
      for(int j=0;j<data[0].length;j++){
        System.out.print(data[i][j]+" ");
      }
      System.out.println();
    }
    System.out.println();
    for(int i=0;i<data2.length;i++){
      for(int j=0;j<data2[0].length;j++){
        System.out.print(data2[i][j]+" ");
      }
      System.out.println();
    }
    System.out.println();
      int[][] data3 = deepClone(data2);
      data3[1][2] = 100;
      data3[0] = new int[]{4,2,1};
      for(int i=0;i<data3.length;i++){
        for(int j=0;j<data3[0].length;j++){
          System.out.print(data3[i][j]+" ");
        }
        System.out.println();
      }
      System.out.println();

  }


  public static int[][] deepClone(int[][] arr){
    int[][] arr2 = new int[arr.length][];
    for(int j=0;j<arr2.length;j++){
      arr2[j] = arr[j].clone();
    }
    return arr2;
  }
}
