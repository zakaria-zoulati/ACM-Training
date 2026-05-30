import java.util.*;

public class Solution {
    static class Trie {
        Trie left  ; 
        Trie right ; 
        int count ; 
        public Trie(){
            this.left = null ; 
            this.right = null ; 
            this.count = 0 ; 
        }
        public void insert( String s ){
            Trie root = this ;  
            for( char c : s.toCharArray()){
                if( c == 'L' ){
                    if( root.left == null ){
                        root.left = new Trie() ; 
                    }
                    root = root.left; 
                }else {
                    if( root.right == null ){
                        root.right = new Trie() ; 
                    }
                    root = root.right; 
                }
                root.count++ ; 
            }
        }
        public int getCount( String s ){
            Trie root = this ;  
            for( char c : s.toCharArray() ){
                if( c == 'L' ){
                    if( root.left == null ) return 0 ; 
                    root = root.left ; 
                }else {
                    if( root.right == null ) return 0 ; 
                    root = root.right ;  
                }
            }
            return root.count ; 
        }
    }
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in) ; 
        Trie t = new Trie() ; 
        int n = sc.nextInt() ; 
        int k = sc.nextInt() ; 
        sc.nextLine() ;
        for( int i=0 ; i<n ; ++i ){
            t.insert(sc.nextLine());
        } 
        for( int i=0 ; i<k ; ++i ){
            System.out.println( t.getCount(sc.nextLine()) ) ; 
        }
    }
}