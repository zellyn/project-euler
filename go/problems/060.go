// Project Euler Problem 060
//
// Find a set of five primes for which any two primes concatenate to
// produce another prime.
//
// 13, 5197, 5701, 6733, 8389

package problems

import (
	"fmt"

	"../primes"
)

type Friendly struct {
	prime   int64
	friends []int64
}

func generateFriendlies(c chan<- Friendly, stop <-chan bool) {
	teni := int64(10)
	for i := 2; ; i++ {
		pi := primes.Get64(i)
		if teni < pi {
			teni *= 10
		}
		friends := []int64{}
		tenj := int64(10)
		for j := 1; j < i; j++ {
			if j == 2 {
				continue // 5 never works
			}
			pj := primes.Get64(j)
			if tenj < pj {
				tenj *= 10
			}
			if primes.IsPrime64(pi*tenj+pj) && primes.IsPrime64(pj*teni+pi) {
				friends = append(friends, pj)
			}
		}
		if len(friends) > 0 {
			select {
			case <-stop:
				return
			case c <- Friendly{pi, friends}:
			}
		}
	}
}

func allFriendsKnown(newFriends, oldFriends []int64) bool {
	j := 0
	for _, friend := range newFriends {
		for ; ; j++ {
			if j == len(oldFriends) || friend < oldFriends[j] {
				return false
			}
			if friend == oldFriends[j] {
				j++
				break
			}
		}
	}
	return true
}

func findFive(c <-chan Friendly, stop chan<- bool) (sum int64) {
	// Map from number to all sets with numbers smaller
	sets := make(map[int64][][]int64)
	for {
		friendly := <-c
		var newSets [][]int64
		for i := len(friendly.friends) - 1; i >= 0; i-- {
			friend := friendly.friends[i]
			newSets = append(newSets, []int64{friend})
			friendSets := sets[friend]
			for _, friendSet := range friendSets {
				if allFriendsKnown(friendSet, friendly.friends) {
					if len(friendSet) == 3 {
						stop <- true
						result := friendly.prime + friend
						result += friendSet[0] + friendSet[1] + friendSet[2]
						return result
					}
					newSet := make([]int64, len(friendSet)+1, len(friendSet)+1)
					copy(newSet, friendSet)
					newSet[len(friendSet)] = friend
					newSets = append(newSets, newSet)
				}
			}
		}
		sets[friendly.prime] = newSets
	}
	return
}

func Problem060() string {
	c, s := make(chan Friendly), make(chan bool)
	go generateFriendlies(c, s)
	sum := findFive(c, s)
	return fmt.Sprint(sum)
}

func init() {
	Functions[60] = Problem060
}
